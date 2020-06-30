using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace _0625_Delegate_Beginning01
{
    public delegate void ClassDelegate(string str);
    // Form1 에서 전달받을 Class의 형태를 가져오지만
    // Class Pointer형태로 전달받아야하기 때문에
    // 중간에 Delegate 속성을 준다.

    class DataSend
    {
        int i = 0;
        bool status;
        ClassDelegate dataSend = null;
        // 클래스 생성 시 선언만 해주고
        Thread TestThread;
        public DataSend()
        {
            TestThread = new Thread(new ThreadStart(ThreadMethod));
            TestThread.Start();
            status = false;
        }

        
        public void setDelegate(ClassDelegate setClassDelegate)
        {
            // 위 Method를 통해 Winform에서 DataSend 객체를 생성하고
            // 실행시킴으로서 dataSend가 실질적으로 할당되고록 한다.
            dataSend = setClassDelegate;
        }

        public void ThreadMethod()
        {
            while (true)
            {
                // 이것이 없으면 status가 false되는 순간
                // Thread가 끝나 사라진다.
                while (status)
                {
                    Thread.Sleep(100);
                    dataSend(i++.ToString());
                }
            }
            
        }

        public void DataStart()
        {
            status = true;
            i = 0;            
        }

        public void DataStop()
        {
            status = false;
        }
    }
}
