/*
    Generate Random Numbers within the circle
    Question Link: https://leetcode.com/problems/generate-random-point-in-a-circle/submissions/
*/
class Solution {
    private:
        double radius=0;
        double x_center=0;
        double y_center=0;
    
    public:
    
    Solution(double radius, double x_center, double y_center) {
        
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
        
    }
    
    vector<double> randPoint() {
        vector<double> vec;
        
        double random1 = (double)rand()/RAND_MAX;
        double angle = random1*2*3.1415926535;
        
        double random2 = (double)rand()/RAND_MAX;
        double line = sqrt(random2)*radius;
        
        double x = x_center + line*cos(angle);
        double y = y_center + line*sin(angle);
        vec.push_back(x);
        vec.push_back(y);
        return vec;
    }
};
