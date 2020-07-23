using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace _0721_Review01.Model
{
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
                if(value < 0)
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

    class Motor
    {
        private string m_motorType = "AC";
        public int motorTypeByNum
        {
            get
            {
                if (m_motorType.Equals("AC"))
                {
                    return 0;
                }
                else
                {
                    return 1;
                }
            }
            set
            {
                if (value == 0)
                {
                    m_motorType = "AC";
                }
                else if (value == 1)
                {
                    m_motorType = "DC";
                }
            }
        }
        public string motorTypeByString
        {
            get
            {
                return m_motorType;
            }
            set
            {
                m_motorType = value;
            }
        }

    }

    class RoateFunction
    {
        private bool m_horizental = false;
        private bool m_vertical = false;

        public int rotation_Enable
        {
            get
            {
                int result = 0;
                if (m_horizental)
                {
                    result += (1 << 1);
                }
                if (m_vertical)
                {
                    result += (1 << 0);
                }
                return result;
            }
            set
            {
                if( (value & 0x02) != 0)
                {
                    m_horizental = true;
                }
                if ((value & 0x01) != 0)
                {
                    m_vertical = true;
                }
            }
        }
        public void setVertical(bool state = true)
        {
            m_vertical = state;
        }
        public void setHorizental(bool state = true)
        {
            m_horizental = state;
        }

        public bool checkHorizental()
        {
            if (m_horizental)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        public bool checkVertical()
        {
            if (m_vertical)
            {
                return true;
            }
            else
            {
                return false;
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
                if(value <= 1)
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
            if(m_currentState > m_step)
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

    class PowerSupplySelection
    {
        public static string AC230 = "AC230";
        public static string AC110 = "AC110";
        public static string DC = "DC_All";
        public static string Consent_Kr = "2_Dot";
        public static string Consent_Cn = "2_Strip";
    }

    class DesignColorSelection
    {
        public static string Red = "RED";
        public static string BLACK = "BLACK";
        public static string White = "WHITE";
    }

    class ActivateTimer
    {
        private uint m_timerUnit = 0;

        private uint max = 0;
        private uint min = 0;

        private uint m_timerValue = 0;

        public uint TimerUnit
        {
            get
            {
                return m_timerUnit;
            }
            set
            {
                m_timerUnit = value;
            }
        }

        public bool setTimerRange(uint min, uint max)
        {
            if (max < min)
            {
                return false;
            }
            else
            {
                return true;
            }
        }

        public void SetTimer(uint timer)
        {
            m_timerValue = (timer / m_timerUnit) * m_timerUnit;
        }

        public uint GetTimer()
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
            while(m_timerValue > 0)
            {
                m_timerValue--;
                Thread.Sleep(1000);
            }
        }


    }
    
}
