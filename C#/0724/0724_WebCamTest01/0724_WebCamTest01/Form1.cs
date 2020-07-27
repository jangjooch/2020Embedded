
using OpenCvSharp;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0724_WebCamTest01
{
    public partial class Form1 : Form
    {

        CvCapture capture;
        // 사친 캡처

        IplImage src;
        // 이미지를 저장할 공간

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            Cv.ReleaseImage(src);
            // 동적할당 되어있기에 해제하여야 한다.
            if (src != null)
            {
                src.Dispose();
            }
        }

        private void Start(object o, EventArgs e)
        {
            try
            {
                capture = CvCapture.FromCamera(CaptureDevice.DShow, 0);
                // 어디에서 읽을 것인지 지정

                capture.SetCaptureProperty(CaptureProperty.FrameWidth, 640);
                capture.SetCaptureProperty(CaptureProperty.FrameHeight, 480);
                // 읽어들이는 이미지 크기지정
                timer1.Enabled = true;
            }
            catch (Exception ex)
            {
                MessageBox.Show("Fail to Read");
                timer1.Enabled = false;
            }
            

        }

        private void Call_WebCamPictures(object o, EventArgs e)
        {
            src = capture.QueryFrame();
            // 캡처된 객체 capture에서 프레임을 읽어
            pictureBoxIpl1.ImageIpl = src;
            // pictureBoxIpl에 뿌린다.
        }

        
    }
}
