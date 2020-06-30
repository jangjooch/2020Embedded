namespace _0624_chart_beginning
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
            System.Windows.Forms.DataVisualization.Charting.Series series2 = new System.Windows.Forms.DataVisualization.Charting.Series();
            this.buttonHigh = new System.Windows.Forms.Button();
            this.buttonLow = new System.Windows.Forms.Button();
            this.chartVoltage = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.buttonStart = new System.Windows.Forms.Button();
            this.buttonStop = new System.Windows.Forms.Button();
            this.timerInterrupt = new System.Windows.Forms.Timer(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.chartVoltage)).BeginInit();
            this.SuspendLayout();
            // 
            // buttonHigh
            // 
            this.buttonHigh.Location = new System.Drawing.Point(12, 12);
            this.buttonHigh.Name = "buttonHigh";
            this.buttonHigh.Size = new System.Drawing.Size(66, 38);
            this.buttonHigh.TabIndex = 0;
            this.buttonHigh.Text = "HIGH";
            this.buttonHigh.UseVisualStyleBackColor = true;
            this.buttonHigh.Click += new System.EventHandler(this.VoltageHigh);
            // 
            // buttonLow
            // 
            this.buttonLow.Location = new System.Drawing.Point(84, 12);
            this.buttonLow.Name = "buttonLow";
            this.buttonLow.Size = new System.Drawing.Size(66, 38);
            this.buttonLow.TabIndex = 1;
            this.buttonLow.Text = "LOW";
            this.buttonLow.UseVisualStyleBackColor = true;
            this.buttonLow.Click += new System.EventHandler(this.VoltageLow);
            // 
            // chartVoltage
            // 
            chartArea1.Name = "ChartArea1";
            this.chartVoltage.ChartAreas.Add(chartArea1);
            legend1.Name = "Legend1";
            this.chartVoltage.Legends.Add(legend1);
            this.chartVoltage.Location = new System.Drawing.Point(12, 56);
            this.chartVoltage.Name = "chartVoltage";
            series1.BorderWidth = 3;
            series1.ChartArea = "ChartArea1";
            series1.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            series1.Color = System.Drawing.Color.Red;
            series1.Legend = "Legend1";
            series1.Name = "DCSensorValue";
            series2.BorderWidth = 3;
            series2.ChartArea = "ChartArea1";
            series2.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            series2.Color = System.Drawing.Color.Blue;
            series2.Legend = "Legend1";
            series2.Name = "Series2";
            this.chartVoltage.Series.Add(series1);
            this.chartVoltage.Series.Add(series2);
            this.chartVoltage.Size = new System.Drawing.Size(574, 345);
            this.chartVoltage.TabIndex = 2;
            this.chartVoltage.Text = "Voltage";
            // 
            // buttonStart
            // 
            this.buttonStart.Location = new System.Drawing.Point(156, 12);
            this.buttonStart.Name = "buttonStart";
            this.buttonStart.Size = new System.Drawing.Size(66, 38);
            this.buttonStart.TabIndex = 3;
            this.buttonStart.Text = "Start";
            this.buttonStart.UseVisualStyleBackColor = true;
            this.buttonStart.Click += new System.EventHandler(this.RandomStart);
            // 
            // buttonStop
            // 
            this.buttonStop.Location = new System.Drawing.Point(228, 12);
            this.buttonStop.Name = "buttonStop";
            this.buttonStop.Size = new System.Drawing.Size(66, 38);
            this.buttonStop.TabIndex = 4;
            this.buttonStop.Text = "Stop";
            this.buttonStop.UseVisualStyleBackColor = true;
            this.buttonStop.Click += new System.EventHandler(this.RandomStop);
            // 
            // timerInterrupt
            // 
            this.timerInterrupt.Tick += new System.EventHandler(this.RandomChart);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(598, 413);
            this.Controls.Add(this.buttonStop);
            this.Controls.Add(this.buttonStart);
            this.Controls.Add(this.chartVoltage);
            this.Controls.Add(this.buttonLow);
            this.Controls.Add(this.buttonHigh);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.chartVoltage)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button buttonHigh;
        private System.Windows.Forms.Button buttonLow;
        private System.Windows.Forms.DataVisualization.Charting.Chart chartVoltage;
        private System.Windows.Forms.Button buttonStart;
        private System.Windows.Forms.Button buttonStop;
        private System.Windows.Forms.Timer timerInterrupt;
    }
}

