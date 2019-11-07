#include<iostream>
#include <string.h>
#include<map>

using namespace std;

int main(){

    char input[100];
    map<string, string> dicctionary;
    bool sig = false;

    while(fgets(input,100, stdin)!=NULL){
        if(strlen(input) == 1){
            sig = true;
            continue;
        }
        else if(input[strlen(input)-1] == '\n')
            input[strlen(input)-1] = '\0';
        if(sig == 0){
            char first_op[12], second_op[12];
            sscanf(input, "%[^ ]", first_op);
            sscanf(input, "%*s%s", second_op);
            string left(&first_op[0], &first_op[strlen(first_op)]);
            string right(&second_op[0], &second_op[strlen(second_op)]);
            dicctionary.insert(make_pair(right, left));
        }
        else{
            string search(&input[0], &input[strlen(input)]);
            auto i = dicctionary.find(search);
            if(i != dicctionary.end())
                cout<<i->second<<endl;
            else cout<<"eh"<<endl;
        }
    }
    return 0;
}