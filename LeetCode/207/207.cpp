// 207.课程表

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {

private:
    vector<vector<int>> edges;  // 边集
    vector<int> visited;  // 标记节点是否访问过
    bool valid = true;    // 标记是否合法

public:
    // 什么时候不能完成？就是死锁啊！什么时候有死锁？构成环啊！
    // 其实就是找有没有环，没有的话可以拓扑排序完成所有课程的
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 把容量变成numCourses这样大
        edges.resize(numCourses);
        visited.resize(numCourses);
        // 自动推断类型，只读不修改
        for (const auto& info: prerequisites) {
            edges[info[1]].push_back(info[0]);  // 前驱 -- 指向 --> 后继
        }
        // 以节点i开始，进行dfs，看看能不能valid？不能的话会在dfs里面改掉的
        for(int i = 0; i < numCourses &&  valid; ++i){
            if(!visited[i]) dfs(i);
        }
        return valid;
    }

    void dfs(int u){
        visited[u] = 1;  // 当前节点 u 到此一游
        for (int v : edges[u]){  // 遍历 u 的所有后继节点 v
            if (visited[v] == 0){
                dfs(v);   // 没有访问过就深搜，不合法回溯return
                if(!valid) return;
            }else if(visited[v] == 1){
                valid = false;   // 当前dfs访问过就直接不合法return
                return;
            }
        }
        visited[u] = 2;  // 表示访问过，且该节点合法，在其他节点dfs时，不会访问该节点
    }
};
