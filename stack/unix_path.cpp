#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

string get_unix_path(string path) {
    string ret;
    string s;
    stack<string> st;
    int len = path.size();

    for (int i=0; i<len; i++) {
        s += path[i];
        if ('/' == path[i] || len == i+1) {
            if (s == "/") {
                if (st.empty()) st.push(s);
            }
            else if (s == ".." || s == "../") {
                if (!st.empty() && st.top() != "/") st.pop();
            }
            else if (s != "." && s != "./") {
                st.push(s);
            }
            s.clear();
        }
    }

    while(!st.empty()) {
        ret = st.top() + ret;
        st.pop();
    }

    return ret;
}

string stanpath(char* a)
{
	stack<string> path;
	string str;

	for(unsigned i=0; i<strlen(a); i++){
		str += a[i];
		if(a[i]=='/' || i+1==strlen(a)){
			if( strcmp(str.c_str(), "../")==0 ||
				strcmp(str.c_str(), "..")==0 ){
				if(!path.empty()){
					if(strcmp(path.top().c_str(), "/"))
						path.pop();
				}
			}
			else if(strcmp(str.c_str(), "/")==0){
					if(path.empty())
						path.push(str);
				 }else
					if(strcmp(str.c_str(), "./") &&
					   strcmp(str.c_str(), ".") )
						path.push(str);

			str = "";
		}
	}

	while(!path.empty()){
		str = path.top().append(str);
		path.pop();
	}
	return str;
}

int main() {
    // string path= "/a/./b/../c/";
    // string path = "/a/./b/../../c/";
    string path;
    cin >> path;
    cout << get_unix_path(path) << endl; 
    cout << stanpath((char *)path.c_str()) << endl; 
    return 1;
}
