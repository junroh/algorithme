// https://www.geeksforgeeks.org/find-the-largest-complete-subtree-in-a-given-binary-tree/
// https://www.geeksforgeeks.org/find-the-largest-perfect-subtree-in-a-given-binary-tree/

import java.util.*;

class Solution {
    class PerfectTree {
        boolean isPerfect;
        boolean isComplete;
        int depth;
        Tree root;
        PerfectTree() {
            root = null;
            isComplete = true;
            isPerfect = true;
            depth = 0;
        }
    }

    private PerfectTree dfs(Tree node) {
        PerfectTree ret = new PerfectTree();
        if(node==null) {
            return ret;
        }
        PerfectTree left = dfs(node.l);
        PerfectTree right = dfs(node.r);
        if(left.isPerfect && right.isComplete && left.depth == right.depth) {
            ret.depth = left.depth+1;
            ret.root = node;
            ret.isPerfect = right.isPerfect;
            return ret;
        }
        if(left.isComplete && right.isPerfect && left.depth == right.depth+1) {
            ret.depth = right.depth+1;
            ret.root = node;
            ret.isPerfect = false;
            return ret;
        }

        ret.isComplete = false;
        ret.isPerfect = false;
        if(left.depth<right.depth) {
            ret.depth = right.depth;
            ret.root = right.root;
        } else {
            ret.depth = left.depth;
            ret.root = left.root;
        }
        return ret;
    }

    public int solution(Tree T) {
        // write your code in Java SE 8
        PerfectTree perfectTree = dfs(T);
        int size = (int)Math.pow(2, perfectTree.depth) - 1;
        return size;
    }
}
