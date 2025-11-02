class Solution {
    public void dfs(List<List<Integer>> graph,boolean[] visited,Stack<Integer> stack,int node){
        visited[node] = true;
        
        for(int neighbour:graph.get(node)){
            if(visited[neighbour]) continue;
            visited[neighbour] = true;
            dfs(graph,visited,stack,neighbour);
        }
        
        stack.push(node);
    }
    public int maxEdgesToAdd(int V, int[][] edges) {
        // Code here
        // return (V * (V-1))/2 - edges.length;
        List<List<Integer>> graph = new ArrayList<>();
        for(int i=0;i<V;i++) graph.add(new ArrayList<>());
        
        Map<Integer,Set<Integer>> map = new HashMap<>();
        for(int[] edge:edges){
            int src = edge[0];
            int dest = edge[1];
            graph.get(src).add(dest);
            map.computeIfAbsent(src,k->new HashSet<>()).add(dest);
        }
        boolean[] visited = new boolean[V];
        Stack<Integer> stack = new Stack<>();
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(graph,visited,stack,i);
            }
        }
        
        List<Integer> list = new ArrayList<>();
        while(!stack.isEmpty()){
            list.add(stack.pop());
        }

        int count = 0;
        
        for(int i=0;i<V-1;i++){
            Set<Integer> curr = map.get(list.get(i));
            if(curr==null) {
                count += V-1 - i;
                continue;
            }
            for(int j=i+1;j<V;j++){
                if(!curr.contains(list.get(j))) count++;
            }
        }
        
        return count;
    }
}