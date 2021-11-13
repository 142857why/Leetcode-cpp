#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const unsigned int n1 = nums1.size();
        const unsigned int n2 = nums2.size();
        // Make sure n1 <= n2;
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);
        const unsigned int k = (n1 + n2 + 1) / 2;

        unsigned int l = 0;
        unsigned int r = n1;
        unsigned m1, m2;
        while (l < r) {
            m1 = l + (r - l) / 2;
            m2 = k - m1;
            if (nums1[m1] < nums2[m2 - 1]) {
                l = m1 + 1;
            } else {
                r = m1;
            }
        }
        m1 = l;
        m2 = k - l;
        const int c1 = std::max(m1 <= 0 ? INT_MIN : nums1[m1 - 1],
                                m2 <= 0 ? INT_MIN : nums2[m2 - 1]);

        if ((n1 + n2) % 2) return (double)c1;

        const int c2 = std::min(m1 >= n1 ? INT_MAX : nums1[m1],
                                m2 >= n2 ? INT_MAX : nums2[m2]);

        return (c1 + c2) / 2.0;
    }
};
int main() {
    vector<int> nums1{-1, 1, 3, 5, 7, 9};
    vector<int> nums2{2, 4, 6, 8, 10, 12, 14, 16};
    auto* obj = new Solution();
    double ans = obj->findMedianSortedArrays(nums1, nums2);
    cout << "ans = " << ans << endl;
    delete obj;
    return 0;
}

/* Explanation:
index: 0  1  2  3  4  5  6  7  8
       -1 1  3  5  7  9
       2 4 6 8  10 12 14 16

n1 = 6, n2 = 8
in total 14 numbers
 - if there are 3 numbers, the (3+1)/2 = 2(nd) one is the medium
 - if there are 4 numbers, the average of the (4+1)/2 = 2(nd) and the 2+1=3(rd) one is the medium
 so the most important index value we care is k = (total + 1) / 2
 in this example, k = (14+1) / 2 = 7
 since 14 is even number, so the k(7th) one and (k+1)8th one are both needed.
 When speaking as index, we need c[6] and c[7], where c is the altogether sorted array,

Now we care about m1 and m2, which is the index of the boundary in the original array a and b
 at last we have 4 numbers in the final round
 known :  m1 + m2 = k
       :  a[m1 - 1] < a[m1]
       :  b[m2 - 1] < b[m2]
       :  a[m1] > b[m2-1]

 the final round means that we already have (m1-1) + (m2-1) = k - 2 numbers 'sorted'
 now the smallest one among this four is the (k-1)th
 the second-smallest one is the kth
 the second-biggest one is  the (k+1)th
 the biggest one is the (k+2) th

 If the total cardinality of the two arrays is even, we care kth and (k+1)th
 If the total cardinality of the two arrays is odd, we care kth

 Case 1: a[m1-1] is the smallest one <==> a[m1-1] < b[m2-1]
            Case 1.1: a[m1-1] < b[m2-1] < a[m1]   < b[m2]
            Case 1.2: a[m1-1] < b[m2-1] < b[m2]   < a[m1]

 Case 2: b[m2-1] is the smallest one <==> b[m2-1] < a[m1-1]
            Case 2.1: b[m2-1] < a[m1-1] < a[m1] < b[m2]
            Case 2.2: b[m2-1] < a[m1-1] < b[m2] < a[m1]

In both big cases, we treat the bigger one between a[m1-1] and b[m2-1] as the kth,
                    and we treat the smaller one between a[m1] and b[m2] as the (k+1)th

 Now question remains to find the boundary m1 and m2
index: 0  1  2  3  4  5  6  7
       -1 1  3  5  7  9
       2  4  6  8  10 12 14 16
 set l = 0, r = n1 = 6 at the beginning
 m1 = 3, m2 = k-m1 = 4, m2-1 = 3 -> a[m1] = 5, b[m2-1] = 8 -> doesn't satisfy a[m1] > b[m2-1] ==> increase l


 l = 4, r = 6
 m1 = 5, m2 = 2, m2-1 = 1 -> a[m1] = 9, b[m2-1] = 4 -> satisfy, but we don't know if it is boundary ==> decrease r

 l = 4, r = m1_old = 5
 m1 = 4, m2 = 3, m2-1 = 2 -> a[m1] = 9, b[m2-1] = 6 -> we don't know if it is boundary => decrease

 l = 4, r = m1_old = 4, l == r

 the last m1 and m2 we got is the boundary!!

For the edge case, we can safely assume that a[-1]=b[-1] = INT_MIN, and a[size1] = b[size2]=INT_MAX

*/