class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // int area1=(rec1[2]-rec1[0])*(rec1[3]-rec1[1]);
        // int area2=(rec2[2]-rec2[0])*(rec2[3]-rec2[1]);
        // Bottom left orner (x1,y1);
        // top right corner (x2,y2);
        // check then overlap on the both axis 

        

        bool x_overlap=rec2[2]>rec1[0] && rec2[0]<rec1[2];
        bool y_overlap=rec1[1]<rec2[3] && rec2[1]<rec1[3];

        return x_overlap && y_overlap;
        
    }
};