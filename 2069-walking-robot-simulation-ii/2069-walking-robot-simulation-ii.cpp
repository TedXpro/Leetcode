class Robot {
    int width;
    int height;
    int yPos;
    int xPos;
    vector<string> directions;
    vector<vector<int>> positions;
    int dir;
public:
    Robot(int width, int height) {
        this->width = width;
        this->height = height;
        directions = {"East", "North", "West", "South"};
        positions = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        xPos = 0;
        yPos = 0;
        dir = 0;
    }
    
    void step(int num) {
        int n = (2 * width + 2 * height - 4); 
        while(num > n)
            num %= n;
        if(num != 0){
            for(int i = 0; i < num; i++){
                if((xPos == width - 1 && dir == 0) || (xPos == 0 && dir == 2))
                    dir = (dir + 1) % 4;
                if((yPos == height - 1 && dir == 1) || (yPos == 0 && dir == 3))
                    dir = (dir + 1) % 4;
                xPos += positions[dir][0];
                yPos += positions[dir][1];
            } 
        }
        else {
            if(xPos == 0 & yPos == 0 && dir == 0)
                dir = 3; 
        } 
    }
    
    vector<int> getPos() {
        return {xPos, yPos};
    }
    
    string getDir() {
        return directions[dir];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obppj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */