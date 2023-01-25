class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int M = matrix.size();
        int N = matrix[0].size();
        pair<int,int> cursor(0,0);

        // mark visited as -200 (impossible value)
        int totalSize = M * N;
        
        vector<int> ret;

        while (ret.size() < totalSize) {

            // order of priority
            while (cursor.second < N-1 && matrix[cursor.first][cursor.second+1] != -200) {
                ret.push_back(matrix[cursor.first][cursor.second]);
                matrix[cursor.first][cursor.second] = -200;
                // move right
                cursor.second++;
                //cout << "RIGHT:"<<cursor.first<<","<<cursor.second<<endl;
            } while (cursor.first < M-1 && matrix[cursor.first+1][cursor.second] != -200) {
                // move down
                ret.push_back(matrix[cursor.first][cursor.second]);
                matrix[cursor.first][cursor.second] = -200;
                cursor.first++;
                //cout << "DOWN:"<<cursor.first<<","<<cursor.second<<endl;
            } while (cursor.second > 0 && matrix[cursor.first][cursor.second-1] != -200) {
                // move left
                ret.push_back(matrix[cursor.first][cursor.second]);
                matrix[cursor.first][cursor.second] = -200;
                cursor.second--;
                //cout << "LEFT:"<<cursor.first<<","<<cursor.second<<endl;
            } while (cursor.first > 0 && matrix[cursor.first-1][cursor.second] != -200) {
                // move up
                ret.push_back(matrix[cursor.first][cursor.second]);
                matrix[cursor.first][cursor.second] = -200;
                cursor.first--;
                //cout << "UP:"<<cursor.first<<","<<cursor.second<<endl;
            }

            if (ret.size() == totalSize - 1) {
                ret.push_back(matrix[cursor.first][cursor.second]);
            }

            //for_each(ret.begin(), ret.end(), [](int a) {cout << a << ",";});
            //cout<<endl;
        }

        return ret;
    }
};