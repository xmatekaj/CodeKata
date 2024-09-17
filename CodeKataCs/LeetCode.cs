using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeKataCs
{
    internal static class LeetCode
    {
        // 884. Uncommon Words from Two Sentences
        // https://leetcode.com/problems/uncommon-words-from-two-sentences/
        public static string[] UncommonFromSentences(string s1, string s2)
        {
            string[] list1 = s1.Split(' ');
            string[] list2 = s2.Split(' ');
            var res = new List<string>();
            foreach (var s in list1)
            {
                int numOfElements = list1.Where(x => x.Equals(s)).Select(x => x).Count();
                if (numOfElements == 1 && !list2.Contains(s)) res.Add(s);
            }
            foreach (var s in list2)
            {
                int numOfElements = list2.Where(x => x.Equals(s)).Select(x => x).Count();
                if (numOfElements == 1 && !list1.Contains(s)) res.Add(s);
            }
            return res.ToArray();
        }
    }
}