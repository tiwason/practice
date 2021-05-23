#include <iostream>
#include <climits>
#include <queue>

using namespace std;

struct NodeData
{
   int data;
   int minRange;
   int maxRange;
   bool leftChk;
   bool rightChk;

   NodeData(int l, int min, int max, bool left, bool right)
   {
       data = l;
       minRange = min;
       maxRange = max;
       leftChk = left;
       rightChk = right;
   }
};


bool chkLevelOrderBST(int levelOrder[], int size)
{
    queue<NodeData> q;
    q.push(NodeData(levelOrder[0], INT_MIN, INT_MAX, false, false));

    for(int index = 1; index<size; index++)
    {
        bool assigned = false;
        while(assigned != true && !q.empty())
        {
            if(levelOrder[index] > q.front().minRange 
                && levelOrder[index] < q.front().data)
               {
                    assigned = true;
                    q.front().leftChk = true;
                    q.push(NodeData(levelOrder[index], q.front().minRange, q.front().data, false, false));
               }
            else if(levelOrder[index] > q.front().data && levelOrder[index] < q.front().maxRange)
            {
                assigned = true;
                q.front().rightChk = true;
                q.push(NodeData(levelOrder[index], q.front().data, q.front().maxRange, false, false));
            }
            else
                q.pop();
            
            if(q.front().leftChk && q.front().rightChk)
                q.pop();            
        }

        if(q.empty() && !assigned)
            return false;
    }
    
    return true;
}


int main()
{
    //int levelOrder[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};
    int levelOrder[] = {11, 6, 13, 5, 12, 10};
    int size = sizeof(levelOrder)/sizeof(levelOrder[0]);

    if (chkLevelOrderBST(levelOrder, size))
        cout << "BST can be constructed !!";
    else
        cout << "BST cant be constructed !!"; 

    cout << endl;  

    return 0;
}