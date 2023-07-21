# XOR加密算法c++加密文件内容

# 什么是XOR加密算法

XOR（异或）是一种逻辑运算符，用于比较两个二进制数的每一位，如果相同则返回 0，否则返回 1。在加密中，XOR 算法通常用于对数据进行加密和解密。

XOR 算法的加密和解密过程非常简单，只需要使用一个密钥（也是一个二进制数），对需要加密或解密的数据进行逐位异或运算即可。具体来说，对于一个二进制数据和一个密钥，XOR 算法会将二进制数据的每一位，与密钥对应位置上的位进行异或运算，得到一个新的二进制数作为加密或解密后的结果。

例如，假设需要将二进制数 0110 进行加密，使用密钥 1011 进行加密。则加密过程如下：

```asciidoc
0110
XOR 1011
-----
1101
因此，加密后的结果为 1101。

同样的，如果想要对加密后的结果进行解密，只需要再次使用相同的密钥对加密后的结果进行异或运算即可。例如，使用密钥 1011 对加密后的结果 1101 进行解密：

```asciidoc
1101
XOR 1011
-----
0110
```

因此，解密后的结果为 0110，与原始数据相同。

需要注意的是，XOR 算法的安全性较低，容易被破解。因此，在实际应用中，需要使用更加安全的加密算法来保护数据的安全。

# 加密代码

```cpp
#include <iostream>
#include <string>
#include <fstream>
#include <iterator>

std::string encryptString(const std::string &input, const std::string &key)
{
    std::string output;
    for (size_t i = 0; i < input.size(); i++)
    {
        output += input[i] ^ key[i % key.size()];
    }
    return output;
}


int main()
{
    std::string input_file_name = "input.txt";
    std::string output_file_name = "output.txt";
    std::string key = "mysecretkey";

    std::ifstream input_file(input_file_name);
    if (!input_file.is_open())
    {
        std::cerr << "Error: Failed to open input file." << std::endl;
        return 1;
    }

    std::string input((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());

    input_file.close();

    std::string encrypted = encryptString(input, key);

    std::ofstream output_file(output_file_name);
    if (!output_file.is_open())
    {
        std::cerr << "Error: Failed to open output file." << std::endl;
        return 1;
    }

    output_file << encrypted;

    output_file.close();

    return 0;
}
```

## 解密代码

```cpp
#include <iostream>
#include <string>
#include <fstream>
#include <iterator>

std::string encryptString(const std::string &input, const std::string &key)
{
    std::string output;
    for (size_t i = 0; i < input.size(); i++)
    {
        output += input[i] ^ key[i % key.size()];
    }
    return output;
}

std::string decryptString(const std::string &input, const std::string &key)
{
    return encryptString(input, key);
}

int main(int argc,char* argv[]) {
    std::string input = argv[1]; //第一个参数接收文件位置
    std::string key = argv[2]; //第二个参数接收key
    std::ifstream input_file(input);
    if (!input_file.is_open())
    {
        std::cerr << "Error: Failed to open input file." << std::endl;
        return 1;
    }

    std::string encrypted((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());

    input_file.close();

    std::string decrypted = decryptString(encrypted,key);
    std::string decrypted_file = "decrypted.txt";

    std::ofstream output_file(decrypted_file);
    if (!output_file.is_open())
    {
        std::cerr << "Error: Failed to open output file." << std::endl;
        return 1;
    }

    output_file << decrypted;

    output_file.close();
}
```
