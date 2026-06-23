class MedianFinder {
    //creation of 2 heaps...MinHeap and a MaxHeap//
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {

        if (maxHeap.empty()) { //keeps the left elements//
            maxHeap.push(num);
        } else {

            if (num <= maxHeap.top()) {

                maxHeap.push(num);

            } else if (num > maxHeap.top()) {
                minHeap.push(num);
            }

        }

        //now equaalize the elements//

        int sz1 = maxHeap.size();
        int sz2 = minHeap.size();

        if (sz1 == sz2+2) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (sz2 > sz1) {

            while (minHeap.size() > maxHeap.size()) {

                maxHeap.push(minHeap.top());
                minHeap.pop();

            }

        }

    }
    
    double findMedian() {
        int sz1 = maxHeap.size();
        int sz2 = minHeap.size();
        if ((sz1+sz2)%2 == 0) {

            //even elements//

            double ans = (double)(minHeap.top()+maxHeap.top())/2;
            return ans;

        } else {

            double ans = (double)(maxHeap.top());
            return ans;

        }
        return 0.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */