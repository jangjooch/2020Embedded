namespace _0623_DataGridView
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
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.buttonGridViewReadAll = new System.Windows.Forms.Button();
            this.buttonGridDataChange01 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(12, 12);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowTemplate.Height = 23;
            this.dataGridView1.Size = new System.Drawing.Size(322, 200);
            this.dataGridView1.TabIndex = 0;
            // 
            // buttonGridViewReadAll
            // 
            this.buttonGridViewReadAll.Location = new System.Drawing.Point(340, 12);
            this.buttonGridViewReadAll.Name = "buttonGridViewReadAll";
            this.buttonGridViewReadAll.Size = new System.Drawing.Size(129, 23);
            this.buttonGridViewReadAll.TabIndex = 1;
            this.buttonGridViewReadAll.Text = "DataReadAll";
            this.buttonGridViewReadAll.UseVisualStyleBackColor = true;
            this.buttonGridViewReadAll.Click += new System.EventHandler(this.DataGridView_ItemReadAll);
            // 
            // buttonGridDataChange01
            // 
            this.buttonGridDataChange01.Location = new System.Drawing.Point(340, 41);
            this.buttonGridDataChange01.Name = "buttonGridDataChange01";
            this.buttonGridDataChange01.Size = new System.Drawing.Size(129, 23);
            this.buttonGridDataChange01.TabIndex = 2;
            this.buttonGridDataChange01.Text = "Data0ValueChange";
            this.buttonGridDataChange01.UseVisualStyleBackColor = true;
            this.buttonGridDataChange01.Click += new System.EventHandler(this.DataGridView_ItemDataChange);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(519, 369);
            this.Controls.Add(this.buttonGridDataChange01);
            this.Controls.Add(this.buttonGridViewReadAll);
            this.Controls.Add(this.dataGridView1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.Button buttonGridViewReadAll;
        private System.Windows.Forms.Button buttonGridDataChange01;
    }
}

