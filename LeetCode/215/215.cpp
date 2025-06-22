// 215.数组中的第K个最大元素

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int quickselect(vector<int> &nums, int l, int r, int k)
    {
        if (l == r)
            return nums[k]; // k其实就是外面传进来的n-k，即第k个最大元素
        // 选择最左边为划分元素
        int partition = nums[l];
        // 索引越界？不是啊，就是要专门从最左侧，最右侧没元素的位置向中间缩！
        int i = l - 1, j = r + 1;
        while (i < j)
        {
            // 当前元素的位置大小关系合法，都向中间缩
            // 注意！这里partition操作只是< > ，等于不管！！！不用像荷兰国旗一样分三份！
            // 比如：6446768  ->  644 6(j) 768   你把6靠在中间不就行了吗？ 446 6(j) 678
            //       这样6作为partition，也到了最终的位置啊，可能有多个索引但是无所谓！
            //       比如我第k个元素是6，我返回6就行，并不需要纠结相同6可能不同索引
            //       反正一定在正确的索引区间返回里面！！！
            do
                i++;
            while (nums[i] < partition);
            do
                j--;
            while (nums[j] > partition);
            // 大小关系不合法，如果此时i<j（正常情况），那交换吧
            // 为什么要再判断i<j呢？因为你前面一直缩都没再次判断...
            if (i < j)
                swap(nums[i], nums[j]);
        }
        // 这里的k就是外面的n-k，哎呀直接理解成第k大的元素就行！绕双层把自己绕晕了...
        // 第k大，实参下标n-k，形参下标k
        // 此处k越小，代表外面传进来的n-k越小，代表第k个元素的k越大，即排位靠后，值越小
        // 那省流只看最前最后，不就是此时的索引k越小，对应的值越小吗？
        // 那我递归就正常理解：【左扩到的边界l，k，j】
        // 这里的k始终是第k个元素的索引n-k，传进来递归就没变过值，想那么多干嘛！！！
        if (k <= j)
            return quickselect(nums, l, j, k);
        else
            return quickselect(nums, j + 1, r, k);
    }

    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        return quickselect(nums, 0, n - 1, n - k); // 升序排序，n-1最大，n-k第k大
    }
};




// 堆排序
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        int dn = n;
        buildMaxHeap(nums);
        for (int i = n - 1; i >= n - k + 1; i--)
        {
            swap(nums[0], nums[i]); // 最后一个元素换到开头，做heapify
            dn--;                   // 开头的最大值元素换到末尾，移除（外层的静态n大小不变）
            heapify(nums, 0, dn);   // 此处由于移除了元素，数组大小是动态的dn
        }
        return nums[0];
    }

    // 构建大根堆
    void buildMaxHeap(vector<int> &nums)
    {
        for (int i = nums.size() / 2 - 1; i >= 0; i--)
        {
            heapify(nums, i, nums.size());
        }
    }

    // 当前节点i往下heapify
    void heapify(vector<int> &nums, int i, int size)
    {
        int left = i * 2 + 1;
        while (left < size)
        {
            // 左右节点选较大值
            int larger = left + 1 < size && nums[left + 1] > nums[left] ? left + 1 : left;
            // 和当前（父节点）比较，选最大值
            int largest = nums[larger] > nums[i] ? larger : i;
            if (largest == i)
                break;                    // 你爸爸还是你爸爸
            swap(nums[largest], nums[i]); // 完了，被篡位了
            i = largest;
            left = i * 2 + 1; // 当前节点（父节点）被打入冷宫，只要不越界，就可能还会再被打
        }
    }
};
