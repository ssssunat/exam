#include<bits/stdc++.h>

int main()
{
    std::string a,b;
    std::cin>>a>>b;
    std::stack<char>ang;
    int left_b=0;
    if(a.size()!=b.size())
        std::cout<<"NO";
    else
    {
       for(int i=0;i<a.size();i++)
       {
            ang.push(a[i]);
            while((ang.size() > 0) && (ang.top() == b[left_b]))
            {
                left_b++;
                ang.pop();
            }
       }
       if(ang.size() == 0)
          std::cout << "YES";
       else
          std::cout<<"NO";
    }
    return 0;
}
