class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        //in 1 minute hour clock cover 0.5 degree//
        //1 hour ---> 30 degree//
        // in the 1 minute 6 degree//


        // ans --> distance by minute hand - distance by hour hand//


        double totalHours = (double)hour + (double)minutes/60;
        double hourDegree = fmod((totalHours*30.00),360);

        double minDegree = fmod((minutes*6) , 360);

        double ans = abs(hourDegree-minDegree);

        return min(ans , abs(360-ans));


    }
};