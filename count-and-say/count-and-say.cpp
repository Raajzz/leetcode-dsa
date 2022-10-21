class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        if(n==2){
            return "11";
        }
        string str = "11";
        for(int i=3; i<=n; i++){
            int num_counter = 1;
            string new_str;
            for(int i=1; i<str.size(); i++){
                if(str[i] == str[i-1]){
                    num_counter++;
                } else {
                    new_str += to_string(num_counter) + str[i-1];
                    num_counter = 1;
                }
            }
            new_str += to_string(num_counter) + str[str.size()-1];
            cout << str << "\n";
            str = new_str;
        }
        return str;
    }
};