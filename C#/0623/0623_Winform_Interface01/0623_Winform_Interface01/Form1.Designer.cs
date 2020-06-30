namespace _0623_Winform_Interface01
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.groupBoxCheckBox = new System.Windows.Forms.GroupBox();
            this.checkBox3 = new System.Windows.Forms.CheckBox();
            this.checkBox2 = new System.Windows.Forms.CheckBox();
            this.checkBox1 = new System.Windows.Forms.CheckBox();
            this.radioButton1 = new System.Windows.Forms.RadioButton();
            this.groupBoxRadioButton = new System.Windows.Forms.GroupBox();
            this.radioButton3 = new System.Windows.Forms.RadioButton();
            this.radioButton2 = new System.Windows.Forms.RadioButton();
            this.buttonCheckBoxTest = new System.Windows.Forms.Button();
            this.buttonRadioButtonTest = new System.Windows.Forms.Button();
            this.pictureBoxChanging01 = new System.Windows.Forms.PictureBox();
            this.timerPictureChange = new System.Windows.Forms.Timer(this.components);
            this.groupBoxCheckBox.SuspendLayout();
            this.groupBoxRadioButton.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxChanging01)).BeginInit();
            this.SuspendLayout();
            // 
            // groupBoxCheckBox
            // 
            this.groupBoxCheckBox.Controls.Add(this.checkBox3);
            this.groupBoxCheckBox.Controls.Add(this.checkBox2);
            this.groupBoxCheckBox.Controls.Add(this.checkBox1);
            this.groupBoxCheckBox.Location = new System.Drawing.Point(12, 12);
            this.groupBoxCheckBox.Name = "groupBoxCheckBox";
            this.groupBoxCheckBox.Size = new System.Drawing.Size(200, 100);
            this.groupBoxCheckBox.TabIndex = 0;
            this.groupBoxCheckBox.TabStop = false;
            this.groupBoxCheckBox.Text = "MultipleSelection";
            // 
            // checkBox3
            // 
            this.checkBox3.AutoSize = true;
            this.checkBox3.Location = new System.Drawing.Point(6, 64);
            this.checkBox3.Name = "checkBox3";
            this.checkBox3.Size = new System.Drawing.Size(86, 16);
            this.checkBox3.TabIndex = 0;
            this.checkBox3.Text = "checkBox3";
            this.checkBox3.UseVisualStyleBackColor = true;
            // 
            // checkBox2
            // 
            this.checkBox2.AutoSize = true;
            this.checkBox2.Location = new System.Drawing.Point(6, 42);
            this.checkBox2.Name = "checkBox2";
            this.checkBox2.Size = new System.Drawing.Size(86, 16);
            this.checkBox2.TabIndex = 0;
            this.checkBox2.Text = "checkBox2";
            this.checkBox2.UseVisualStyleBackColor = true;
            // 
            // checkBox1
            // 
            this.checkBox1.AutoSize = true;
            this.checkBox1.Location = new System.Drawing.Point(6, 20);
            this.checkBox1.Name = "checkBox1";
            this.checkBox1.Size = new System.Drawing.Size(86, 16);
            this.checkBox1.TabIndex = 0;
            this.checkBox1.Text = "checkBox1";
            this.checkBox1.UseVisualStyleBackColor = true;
            // 
            // radioButton1
            // 
            this.radioButton1.AutoSize = true;
            this.radioButton1.Location = new System.Drawing.Point(6, 20);
            this.radioButton1.Name = "radioButton1";
            this.radioButton1.Size = new System.Drawing.Size(92, 16);
            this.radioButton1.TabIndex = 1;
            this.radioButton1.TabStop = true;
            this.radioButton1.Text = "radioButton1";
            this.radioButton1.UseVisualStyleBackColor = true;
            this.radioButton1.CheckedChanged += new System.EventHandler(this.RadioImageChange);
            // 
            // groupBoxRadioButton
            // 
            this.groupBoxRadioButton.Controls.Add(this.radioButton3);
            this.groupBoxRadioButton.Controls.Add(this.radioButton2);
            this.groupBoxRadioButton.Controls.Add(this.radioButton1);
            this.groupBoxRadioButton.Location = new System.Drawing.Point(12, 118);
            this.groupBoxRadioButton.Name = "groupBoxRadioButton";
            this.groupBoxRadioButton.Size = new System.Drawing.Size(200, 100);
            this.groupBoxRadioButton.TabIndex = 0;
            this.groupBoxRadioButton.TabStop = false;
            this.groupBoxRadioButton.Text = "SingleSelection";
            // 
            // radioButton3
            // 
            this.radioButton3.AutoSize = true;
            this.radioButton3.Location = new System.Drawing.Point(6, 64);
            this.radioButton3.Name = "radioButton3";
            this.radioButton3.Size = new System.Drawing.Size(92, 16);
            this.radioButton3.TabIndex = 1;
            this.radioButton3.TabStop = true;
            this.radioButton3.Text = "radioButton3";
            this.radioButton3.UseVisualStyleBackColor = true;
            this.radioButton3.CheckedChanged += new System.EventHandler(this.RadioImageChange);
            // 
            // radioButton2
            // 
            this.radioButton2.AutoSize = true;
            this.radioButton2.Location = new System.Drawing.Point(6, 42);
            this.radioButton2.Name = "radioButton2";
            this.radioButton2.Size = new System.Drawing.Size(92, 16);
            this.radioButton2.TabIndex = 1;
            this.radioButton2.TabStop = true;
            this.radioButton2.Text = "radioButton2";
            this.radioButton2.UseVisualStyleBackColor = true;
            this.radioButton2.CheckedChanged += new System.EventHandler(this.RadioImageChange);
            // 
            // buttonCheckBoxTest
            // 
            this.buttonCheckBoxTest.Location = new System.Drawing.Point(218, 25);
            this.buttonCheckBoxTest.Name = "buttonCheckBoxTest";
            this.buttonCheckBoxTest.Size = new System.Drawing.Size(75, 23);
            this.buttonCheckBoxTest.TabIndex = 1;
            this.buttonCheckBoxTest.Text = "CheckBox";
            this.buttonCheckBoxTest.UseVisualStyleBackColor = true;
            this.buttonCheckBoxTest.Click += new System.EventHandler(this.CheckBoxSelectionReceive);
            // 
            // buttonRadioButtonTest
            // 
            this.buttonRadioButtonTest.Location = new System.Drawing.Point(218, 131);
            this.buttonRadioButtonTest.Name = "buttonRadioButtonTest";
            this.buttonRadioButtonTest.Size = new System.Drawing.Size(75, 23);
            this.buttonRadioButtonTest.TabIndex = 2;
            this.buttonRadioButtonTest.Text = "RadioButton";
            this.buttonRadioButtonTest.UseVisualStyleBackColor = true;
            this.buttonRadioButtonTest.Click += new System.EventHandler(this.RadioBoxSelectionReceive);
            // 
            // pictureBoxChanging01
            // 
            this.pictureBoxChanging01.Image = ((System.Drawing.Image)(resources.GetObject("pictureBoxChanging01.Image")));
            this.pictureBoxChanging01.Location = new System.Drawing.Point(299, 118);
            this.pictureBoxChanging01.Name = "pictureBoxChanging01";
            this.pictureBoxChanging01.Size = new System.Drawing.Size(189, 134);
            this.pictureBoxChanging01.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.pictureBoxChanging01.TabIndex = 3;
            this.pictureBoxChanging01.TabStop = false;
            // 
            // timerPictureChange
            // 
            this.timerPictureChange.Interval = 3000;
            this.timerPictureChange.Tick += new System.EventHandler(this.TimerPicureChange);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(540, 277);
            this.Controls.Add(this.pictureBoxChanging01);
            this.Controls.Add(this.buttonRadioButtonTest);
            this.Controls.Add(this.buttonCheckBoxTest);
            this.Controls.Add(this.groupBoxRadioButton);
            this.Controls.Add(this.groupBoxCheckBox);
            this.Name = "Form1";
            this.Text = "Form1";
            this.groupBoxCheckBox.ResumeLayout(false);
            this.groupBoxCheckBox.PerformLayout();
            this.groupBoxRadioButton.ResumeLayout(false);
            this.groupBoxRadioButton.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxChanging01)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBoxCheckBox;
        private System.Windows.Forms.RadioButton radioButton1;
        private System.Windows.Forms.CheckBox checkBox3;
        private System.Windows.Forms.CheckBox checkBox2;
        private System.Windows.Forms.CheckBox checkBox1;
        private System.Windows.Forms.GroupBox groupBoxRadioButton;
        private System.Windows.Forms.RadioButton radioButton3;
        private System.Windows.Forms.RadioButton radioButton2;
        private System.Windows.Forms.Button buttonCheckBoxTest;
        private System.Windows.Forms.Button buttonRadioButtonTest;
        private System.Windows.Forms.PictureBox pictureBoxChanging01;
        private System.Windows.Forms.Timer timerPictureChange;
    }
}

