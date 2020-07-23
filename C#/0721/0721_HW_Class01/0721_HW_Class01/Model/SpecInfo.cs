using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace _0721_HW_Class01.Model
{
    class ModelName
    {
        private string m_name;
        public string Name
        {
            get
            {
                return m_name;
            }
            set
            {
                m_name = value;
            }
        }
    }

    class Wing
    {
        private UInt32 m_count = 0;

        public UInt32 count
        {
            get
            {
                return m_count;
            }
            set
            {
                if (value < 0)
                {
                    m_count = 0;
                }
                else
                {
                    m_count = value;
                }
            }
        }
    }

    class WindPower
    {
        private int m_currentState = 0;
        private int m_step = 3;

        public int step
        {
            get
            {
                return m_step;
            }
            set
            {
                if (value <= 1)
                {
                    m_step = 1;
                }
                else
                {
                    m_step = value;
                }
            }
        }

        public bool PowerUp()
        {
            m_currentState++;
            if (m_currentState > m_step)
            {
                m_currentState = m_step;
                return false;
            }
            else
            {
                return true;
            }
        }

        public bool PowerDown()
        {
            m_currentState--;
            if (m_currentState < 0)
            {
                m_currentState = 0;
                return false;
            }
            else
            {
                return true;
            }
        }
        public int getCurrentState()
        {
            return m_currentState;
        }
    }

    class DesignColorSelection
    {
        public static string Red = "RED";
        public static string BLACK = "BLACK";
        public static string White = "WHITE";
    }

    class ActivateTimer
    {
        private int m_timerValue = 0;

        public void SetTimer(int timer)
        {
            m_timerValue = timer;
        }

        public int GetTimer()
        {
            return m_timerValue;
        }

        Thread thread;

        public void timerOn()
        {
            thread = new Thread(new ThreadStart(operateTimer));
            thread.Start();
        }

        public void timerOff()
        {
            if (thread.IsAlive)
            {
                thread.Abort();
            }
        }

        private void operateTimer()
        {
            while (m_timerValue > 0)
            {
                m_timerValue--;
                Thread.Sleep(1000);
            }
        }
    }

    class Remote
    {
        public static string Wifi = "WIFI";
        public static string BlueTooth = "BT";
    }

    class ConnectTimer
    {
        int m_timerValue = 3;

        Thread thread;

        public void timerOn()
        {
            thread = new Thread(new ThreadStart(operateTimer));
            thread.Start();
        }

        public void timerOff()
        {
            if (thread.IsAlive)
            {
                thread.Abort();
            }
        }

        private void operateTimer()
        {
            while (m_timerValue > 0)
            {
                m_timerValue--;
                Thread.Sleep(1000);
            }
        }
    }
}
