class Solution {
public:
   void DFS(int ind, int l, int r, const string &s, vector<string> &ret, string &path) {
    // l is the number of '('s and r is the number of ')'s in path
	if(r>l) return;
	
	if(ind==s.size()) {
	    // if !ret.empty(), we find one longest valid string
		if(l==r && (ret.empty() || path.size()==ret[0].size())) 
		    ret.push_back(path);
		return;
	}
	
	if(!ret.empty())
	    if(path.size() + s.size() - ind < ret[0].size()) return;
	
	char c = s[ind++];
	path.push_back(c);
	if(c!='(' && c!=')')
		DFS(ind,l,r,s,ret,path);
	else if(c=='(')
		DFS(ind,l+1,r,s,ret,path);
	else 
		DFS(ind,l,r+1,s,ret,path);
	
	path.pop_back();
	if(c!='(' && c!=')')
	    DFS(ind,l,r,s,ret,path);
	else {
	    //once decide to give up current '(' or ')', we do not need to try the continuous '('s or ')'s
	    while(c==s[ind]) ++ind;
	    DFS(ind,l,r,s,ret,path);
	}
}

vector<string> removeInvalidParentheses(string s) {
	vector<string> ret;
	string path;
	DFS(0,0,0,s,ret,path);
	if(ret.empty()) return {""};
	return ret;
}

};
