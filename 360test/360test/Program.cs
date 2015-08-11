using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _360test
{
    class Program
    {
        public int[] Getpeople(int n, int m, Dictionary<int, int> dic)
        {
            int[] result={0};
            int x=0;
            for (int i = 0; i < n; i++)
            {
                if(dic.ContainsKey(i))
                    continue;
                else
                {
                    int j = 0;
                    for (; j < n; j++)
                    {
                        if (!dic.Contains(new KeyValuePair<int, int>(j, i)))
                            break;
                         
                    }
                    if (j < n)
                        continue;
                    else
                        result[x++] = i;
                }

            }
            return result;
        }
        static void Main(string[] args)
        {
        }
    }
}
