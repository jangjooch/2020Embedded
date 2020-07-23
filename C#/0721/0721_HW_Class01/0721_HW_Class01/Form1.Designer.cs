namespace _0721_HW_Class01
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
            this.textBox2R = new System.Windows.Forms.TextBox();
            this.textBox3W = new System.Windows.Forms.TextBox();
            this.label10 = new System.Windows.Forms.Label();
            this.label3002R = new System.Windows.Forms.Label();
            this.label4004B0 = new System.Windows.Forms.Label();
            this.buttonStart = new System.Windows.Forms.Button();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.dataGridView2 = new System.Windows.Forms.DataGridView();
            this.timerProduce = new System.Windows.Forms.Timer(this.components);
            this.timerTest = new System.Windows.Forms.Timer(this.components);
            this.label4003W = new System.Windows.Forms.Label();
            this.textBox4B = new System.Windows.Forms.TextBox();
            this.textBox5R = new System.Windows.Forms.TextBox();
            this.label4005R1 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).BeginInit();
            this.SuspendLayout();
            // 
            // textBox2R
            // 
            this.textBox2R.Location = new System.Drawing.Point(89, 35);
            this.textBox2R.Name = "textBox2R";
            this.textBox2R.Size = new System.Drawing.Size(100, 21);
            this.textBox2R.TabIndex = 7;
            // 
            // textBox3W
            // 
            this.textBox3W.Location = new System.Drawing.Point(89, 62);
            this.textBox3W.Name = "textBox3W";
            this.textBox3W.Size = new System.Drawing.Size(100, 21);
            this.textBox3W.TabIndex = 8;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(15, 14);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(43, 12);
            this.label10.TabIndex = 9;
            this.label10.Text = "Orders";
            // 
            // label3002R
            // 
            this.label3002R.AutoSize = true;
            this.label3002R.Location = new System.Drawing.Point(15, 38);
            this.label3002R.Name = "label3002R";
            this.label3002R.Size = new System.Drawing.Size(25, 12);
            this.label3002R.TabIndex = 9;
            this.label3002R.Text = "32R";
            // 
            // label4004B0
            // 
            this.label4004B0.AutoSize = true;
            this.label4004B0.Location = new System.Drawing.Point(15, 92);
            this.label4004B0.Name = "label4004B0";
            this.label4004B0.Size = new System.Drawing.Size(31, 12);
            this.label4004B0.TabIndex = 9;
            this.label4004B0.Text = "44B0";
            // 
            // buttonStart
            // 
            this.buttonStart.Location = new System.Drawing.Point(114, 143);
            this.buttonStart.Name = "buttonStart";
            this.buttonStart.Size = new System.Drawing.Size(75, 23);
            this.buttonStart.TabIndex = 10;
            this.buttonStart.Text = "Start";
            this.buttonStart.UseVisualStyleBackColor = true;
            this.buttonStart.Click += new System.EventHandler(this.OrderConfirm);
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(322, 12);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowTemplate.Height = 23;
            this.dataGridView1.Size = new System.Drawing.Size(563, 273);
            this.dataGridView1.TabIndex = 11;
            // 
            // dataGridView2
            // 
            this.dataGridView2.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView2.Location = new System.Drawing.Point(322, 296);
            this.dataGridView2.Name = "dataGridView2";
            this.dataGridView2.RowTemplate.Height = 23;
            this.dataGridView2.Size = new System.Drawing.Size(563, 282);
            this.dataGridView2.TabIndex = 12;
            // 
            // timerProduce
            // 
            this.timerProduce.Interval = 3000;
            this.timerProduce.Tick += new System.EventHandler(this.TimerProduceInterrupt);
            // 
            // timerTest
            // 
            this.timerTest.Interval = 500;
            this.timerTest.Tick += new System.EventHandler(this.TimerTestInterrupt);
            // 
            // label4003W
            // 
            this.label4003W.AutoSize = true;
            this.label4003W.Location = new System.Drawing.Point(15, 65);
            this.label4003W.Name = "label4003W";
            this.label4003W.Size = new System.Drawing.Size(27, 12);
            this.label4003W.TabIndex = 9;
            this.label4003W.Text = "43W";
            // 
            // textBox4B
            // 
            this.textBox4B.Location = new System.Drawing.Point(89, 89);
            this.textBox4B.Name = "textBox4B";
            this.textBox4B.Size = new System.Drawing.Size(100, 21);
            this.textBox4B.TabIndex = 8;
            // 
            // textBox5R
            // 
            this.textBox5R.Location = new System.Drawing.Point(89, 116);
            this.textBox5R.Name = "textBox5R";
            this.textBox5R.Size = new System.Drawing.Size(100, 21);
            this.textBox5R.TabIndex = 8;
            // 
            // label4005R1
            // 
            this.label4005R1.AutoSize = true;
            this.label4005R1.Location = new System.Drawing.Point(15, 119);
            this.label4005R1.Name = "label4005R1";
            this.label4005R1.Size = new System.Drawing.Size(31, 12);
            this.label4005R1.TabIndex = 9;
            this.label4005R1.Text = "45R1";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(897, 586);
            this.Controls.Add(this.dataGridView2);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.buttonStart);
            this.Controls.Add(this.label4005R1);
            this.Controls.Add(this.label4004B0);
            this.Controls.Add(this.label4003W);
            this.Controls.Add(this.label3002R);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.textBox5R);
            this.Controls.Add(this.textBox4B);
            this.Controls.Add(this.textBox3W);
            this.Controls.Add(this.textBox2R);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.TextBox textBox2R;
        private System.Windows.Forms.TextBox textBox3W;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label3002R;
        private System.Windows.Forms.Label label4004B0;
        private System.Windows.Forms.Button buttonStart;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.DataGridView dataGridView2;
        private System.Windows.Forms.Timer timerProduce;
        private System.Windows.Forms.Timer timerTest;
        private System.Windows.Forms.Label label4003W;
        private System.Windows.Forms.TextBox textBox4B;
        private System.Windows.Forms.TextBox textBox5R;
        private System.Windows.Forms.Label label4005R1;
    }
}

