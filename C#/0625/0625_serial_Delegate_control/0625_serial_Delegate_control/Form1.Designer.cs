namespace _0625_serial_Delegate_control
{
    partial class Form1
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea1 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend1 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series1 = new System.Windows.Forms.DataVisualization.Charting.Series();
            this.buttonSerialOpen = new System.Windows.Forms.Button();
            this.buttonSerialClose = new System.Windows.Forms.Button();
            this.textBoxValue = new System.Windows.Forms.TextBox();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.chartADCValue = new System.Windows.Forms.DataVisualization.Charting.Chart();
            ((System.ComponentModel.ISupportInitialize)(this.chartADCValue)).BeginInit();
            this.SuspendLayout();
            // 
            // buttonSerialOpen
            // 
            this.buttonSerialOpen.Location = new System.Drawing.Point(9, 12);
            this.buttonSerialOpen.Name = "buttonSerialOpen";
            this.buttonSerialOpen.Size = new System.Drawing.Size(75, 23);
            this.buttonSerialOpen.TabIndex = 0;
            this.buttonSerialOpen.Text = "Open";
            this.buttonSerialOpen.UseVisualStyleBackColor = true;
            // 
            // buttonSerialClose
            // 
            this.buttonSerialClose.Location = new System.Drawing.Point(90, 12);
            this.buttonSerialClose.Name = "buttonSerialClose";
            this.buttonSerialClose.Size = new System.Drawing.Size(75, 23);
            this.buttonSerialClose.TabIndex = 1;
            this.buttonSerialClose.Text = "Close";
            this.buttonSerialClose.UseVisualStyleBackColor = true;
            // 
            // textBoxValue
            // 
            this.textBoxValue.Location = new System.Drawing.Point(171, 14);
            this.textBoxValue.Name = "textBoxValue";
            this.textBoxValue.Size = new System.Drawing.Size(116, 21);
            this.textBoxValue.TabIndex = 2;
            // 
            // chartADCValue
            // 
            chartArea1.Name = "ChartArea1";
            this.chartADCValue.ChartAreas.Add(chartArea1);
            legend1.Name = "Legend1";
            this.chartADCValue.Legends.Add(legend1);
            this.chartADCValue.Location = new System.Drawing.Point(9, 114);
            this.chartADCValue.Name = "chartADCValue";
            series1.BorderWidth = 3;
            series1.ChartArea = "ChartArea1";
            series1.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            series1.Color = System.Drawing.Color.Red;
            series1.Legend = "Legend1";
            series1.Name = "Series1";
            this.chartADCValue.Series.Add(series1);
            this.chartADCValue.Size = new System.Drawing.Size(417, 300);
            this.chartADCValue.TabIndex = 3;
            this.chartADCValue.Text = "chart1";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(438, 426);
            this.Controls.Add(this.chartADCValue);
            this.Controls.Add(this.textBoxValue);
            this.Controls.Add(this.buttonSerialClose);
            this.Controls.Add(this.buttonSerialOpen);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.chartADCValue)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button buttonSerialOpen;
        private System.Windows.Forms.Button buttonSerialClose;
        private System.Windows.Forms.TextBox textBoxValue;
        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.DataVisualization.Charting.Chart chartADCValue;
    }
}

