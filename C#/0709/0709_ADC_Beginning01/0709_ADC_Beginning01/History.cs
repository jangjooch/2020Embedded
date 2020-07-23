using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0709_ADC_Beginning01
{
    class History
    {

        public Dictionary<DateTime, int> lightSensor = new Dictionary<DateTime, int>();

        private static History his = null;

        private History()
        {

        }

        public static History CreateHistory()
        {
            if(his == null)
            {
                his = new History();
            }
            return his;
        }


    }
}
