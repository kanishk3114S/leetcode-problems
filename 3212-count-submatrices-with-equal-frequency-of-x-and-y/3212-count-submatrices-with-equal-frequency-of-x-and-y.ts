function numberOfSubmatrices(grid: string[][]): number {
    const m = grid.length;
    const n = grid[0].length;

    // 2D array storing pairs [countX, countY]
    const vec: [number, number][][] = Array.from({ length: m }, () =>
        Array.from({ length: n }, () => [0, 0])
    );

    let ans = 0;

    for (let i = 0; i < m; i++) {
        let hash = [0, 0]; // [countX, countY]
        let prev = i - 1;

        for (let j = 0; j < n; j++) {
            let temp1 = 0, temp2 = 0;

            if (prev !== -1) {
                temp1 = vec[prev][j][0];
                temp2 = vec[prev][j][1];
            }

            if (grid[i][j] === 'X') hash[0]++;
            else if (grid[i][j] === 'Y') hash[1]++;

            vec[i][j] = [hash[0] + temp1, hash[1] + temp2];

            if (
                vec[i][j][0] > 0 &&
                vec[i][j][0] === vec[i][j][1]
            ) {
                ans++;
            }
        }
    }

    return ans;
}