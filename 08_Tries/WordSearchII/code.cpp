class Solution {

private: 
    struct TrieNode {
        TrieNode* children[26];
        string word;

        TrieNode(){
            for(int i = 0 ; i < 26 ; i++) children[i] = nullptr;
            word = "";
        }
    };

    TrieNode *root;
    int rows , cols;
    vector<string> result;
    vector<int> dirX = {1 , -1 , 0 , 0};
    vector<int> dirY = {0 , 0 , 1 , -1};


public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.empty()) return {};

        root = new TrieNode();
        rows = board.size();
        cols = board[0].size();

        for(string &word : words){
            TrieNode* node = root;
            for(char c : word){
                int idx = c - 'a';
                if(!node->children[idx])
                    node->children[idx] = new TrieNode();
                node = node->children[idx];
            }
            node->word = word;
        }

        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols; j++){
                dfs(board , i , j , root);
            }
        }

        return result;
        
    }

private: 
    void dfs(vector<vector<char>> &board , int x , int y , TrieNode *node){
        char c = board[x][y];
        if(c == '#' || !node->children[c-'a']) return ;

        node = node->children[c-'a'];

        if(!node->word.empty()){
            result.push_back(node->word);
            node->word = "";
        }

        board[x][y] = '#';

        for(int d = 0 ; d < 4 ; d++){
            int nx = x + dirX[d];
            int ny = y + dirY[d];
            if(nx >= 0 && ny >= 0 && nx < rows && ny < cols){
                dfs(board , nx , ny , node);
            }
        }

        board[x][y] = c;
    }

};
