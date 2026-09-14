class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        // Claculate the Indiviual Area of each reactangle 
        int area1=(ax2-ax1)*(ay2-ay1);
        int area2=(bx2-bx1)*(by2-by1);

        // overlap Area 
        int length=max(0,min(ax2,bx2)-max(ax1,bx1));
        int height=max(0,min(ay2,by2)-max(ay1,by1));

        int common_Area=length*height;

        int total_area=area1+area2-common_Area;
        return total_area;
    }
};