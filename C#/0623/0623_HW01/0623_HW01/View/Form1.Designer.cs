namespace _0623_HW01
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
            this.buttonAdd = new System.Windows.Forms.Button();
            this.buttonSear = new System.Windows.Forms.Button();
            this.buttonDel = new System.Windows.Forms.Button();
            this.timerInterrupt = new System.Windows.Forms.Timer(this.components);
            this.SuspendLayout();
            // 
            // buttonAdd
            // 
            this.buttonAdd.Location = new System.Drawing.Point(12, 12);
            this.buttonAdd.Name = "buttonAdd";
            this.buttonAdd.Size = new System.Drawing.Size(75, 23);
            this.buttonAdd.TabIndex = 0;
            this.buttonAdd.Text = "ADD";
            this.buttonAdd.UseVisualStyleBackColor = true;
            this.buttonAdd.Click += new System.EventHandler(this.buttonAdd_Click);
            // 
            // buttonSear
            // 
            this.buttonSear.Location = new System.Drawing.Point(12, 41);
            this.buttonSear.Name = "buttonSear";
            this.buttonSear.Size = new System.Drawing.Size(75, 23);
            this.buttonSear.TabIndex = 1;
            this.buttonSear.Text = "SEARCH";
            this.buttonSear.UseVisualStyleBackColor = true;
            this.buttonSear.Click += new System.EventHandler(this.buttonSear_Click);
            // 
            // buttonDel
            // 
            this.buttonDel.Location = new System.Drawing.Point(12, 70);
            this.buttonDel.Name = "buttonDel";
            this.buttonDel.Size = new System.Drawing.Size(75, 23);
            this.buttonDel.TabIndex = 2;
            this.buttonDel.Text = "DELETE";
            this.buttonDel.UseVisualStyleBackColor = true;
            this.buttonDel.Click += new System.EventHandler(this.buttonDel_Click);
            // 
            // timerInterrupt
            // 
            this.timerInterrupt.Interval = 5000;
            this.timerInterrupt.Tick += new System.EventHandler(this.timerInterrupt_Tick);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(344, 270);
            this.Controls.Add(this.buttonDel);
            this.Controls.Add(this.buttonSear);
            this.Controls.Add(this.buttonAdd);
            this.Name = "Form1";
            this.Text = "Form1";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.Form1_FormClosed);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button buttonAdd;
        private System.Windows.Forms.Button buttonSear;
        private System.Windows.Forms.Button buttonDel;
        private System.Windows.Forms.Timer timerInterrupt;
    }
}

