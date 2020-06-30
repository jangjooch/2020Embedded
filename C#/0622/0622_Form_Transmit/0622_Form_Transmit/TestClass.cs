using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0622_Form_Transmit
{
    class TestClass
    {
        private static TestClass instance = null;
        public static TestClass GetInstance()
        {
            if (instance == null)
            {
                instance = new TestClass();
            }
            return instance;
        }

        // private 형태로 생성자를 생성하면 일반적인 new 방식으로는 객체를 생성할 수 없다.
        // 즉 GetInstance를 통해서만 TestClass 객체를 생성할 수 있도록 지정하는 것이다.
        // 단 GetInstance가 한번 실행되고 나면 다시는 생성되지 않는다.
        // 즉 static처럼 사용할 수 있도록 생성하는것이다.
        private TestClass()
        {

        }

        public string name = "NULL";        

        
    }
}
