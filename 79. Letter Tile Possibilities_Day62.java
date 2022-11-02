    public int numTilePossibilities(String tiles) {
         Set<String> ans = new HashSet<>();
         genWays(tiles,0,"",ans,new HashSet<>());
         return ans.size();
    }
    private static void genWays(String ques,int index,String ans,Set<String> cur,Set<Integer> vis) {
        if(index == ques.length()) {
            return;
        }
        for(int i = 0; i < ques.length(); i++) {
            if(!vis.contains(i)) {
                vis.add(i);
                cur.add(ans + ques.charAt(i));
                genWays(ques,index + 1,ans + ques.charAt(i),cur,vis);
                vis.remove(i);
            }
        }
    }
