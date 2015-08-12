using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _360test
{
    class Program
    {
        /// <summary>
        /// 获得镇长的列表
        /// </summary>
        /// <param name="n"></param>小镇人数
        /// <param name="m"></param>关系数
        /// <param name="dic"></param>关系映射集合
        /// <returns></returns>
        public static int[] GetPeople(int n, int m, Dictionary<int, int> dic)
        {
            int[] result=new int[n];
            int x=0;
            for (int i = 1; i <= n; i++)
            {
                if(dic.ContainsKey(i))
                    continue;
                else
                {
                    int j = 1;
                    for (; j <= n; j++)
                    {
                        //跳过自己（自己默认认识自己）
                        if (j != i)
                        {
                            if (!dic.Contains(new KeyValuePair<int, int>(j, i)))
                                break;
                        }
                         
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
            //SortedList<int, int> so = new SortedList<int, int>();
            //so.Add(1, 2);
            //so.Add(2, 3);
            //so.Add(5, 1);
            //so.Add(3, 2);
            int[] res;
            Dictionary<int, int> dic = new Dictionary<int, int>();//保存关系
            int T;//组数
            Console.WriteLine("请输入要测试的组数：");
            T = Convert.ToInt32(Console.ReadLine());
            int n, m;//分别为小镇人数和关系数
            Console.WriteLine("请输入小镇人数和关系数：");
            n = Convert.ToInt32(Console.ReadLine());
            m = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("请分别输入关系映射：");
            for (int i = 0; i < m; i++)
            {
                Console.WriteLine("请输入第" + (i + 1) + "组关系：");
                int first = Convert.ToInt32(Console.ReadLine());
                int second = Convert.ToInt32(Console.ReadLine());
                dic.Add(first, second);
            }
            res = GetPeople(n, m, dic);
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                if (res[i] == 0)
                    break;
                count++;
            }

            Console.WriteLine("适合当镇长的人数是：" + count + "编号如下：");
            if (count > 0)
            {
                for (int i = 0; i < count; i++)
                {
                    Console.Write(res[i] + " ");
                }
            }
            else
            {
                Console.WriteLine("0");
            }
            Console.WriteLine();

        }
    }
}
