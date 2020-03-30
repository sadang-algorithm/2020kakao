#include <string>
#include <vector>
#include <iostream>
using namespace std;

int countLength(int count)
{
  if (count < 10)
  {
    return 1;
  }
  else if (count < 100)
  {
    return 2;
  }
  else if (count < 1000)
  {
    return 3;
  }
  else
    return 4;
}
int solution(string s)
{
  int answer = 987654321;
  int n = s.size();
  if (n == 1)
    return 1;
  for (int i = 1; i <= n / 2; i++)
  {
    int count = 1;
    int tmpLength = n;
    for (int j = 0; j <= n - 2 * i; j += i)
    {
      string prevStr = s.substr(j, i);
      string nextStr = s.substr(j + i, i);
      if (prevStr.compare(nextStr) == 0)
        count++;
      else if (count != 1)
      {

        tmpLength = tmpLength - (count - 1) * i + countLength(count);
        count = 1;
      }
    }
    if (count != 1)
      tmpLength = tmpLength - (count - 1) * i + countLength(count);
    answer = answer < tmpLength ? answer : tmpLength;
  }
  return answer;
}

int main()
{
  string s = "a";
  cout << solution(s) << endl;
}