# std::stable_partition

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
// 这里我们就用stable_partition来把一个vector数组中的偶数和奇数分开
int main(void) {
  std::vector<int> numbers{1,2,3,4,5,6,7,8,9,10};
  std::cout << "Original numbers: ";
  for_each(numbers.begin(),numbers.end(),[](int val){
    std::cout << val << " ";
  });
  std::cout << std::endl;
  auto middle = std::stable_partition(numbers.begin(),numbers.end(),[](int num){
    return num%2 == 0;
  });
  std::cout << "Partitioned numbers: ";
  for(auto it = numbers.begin();it != middle;it++) {
    std::cout << *it << " ";
  }
  std::cout << " | ";
  for(auto it = middle;it!=numbers.end();it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  return 0;
}
```
