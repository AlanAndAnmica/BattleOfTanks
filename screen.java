package game;

public class screen {
	public static void main(String[]arges){
		//��Ϸ�����ı�ʾ//��Ϸ���ڵĵĴ�С����λ���أ�
	 final int WINDOW_WIDTH=800;
	 final int WINDOW_HEIGHT=800;
	 final float PI=3.1415926F;
	 //̹�˵�λ��
	 int x=0;
	 int y=0;
	 //̹�˵Ĵ�С
	 int w=50;int h=50;
	 //̹�˵��ٶ�
	 int speed=10;
	 //̹�˵�����
	 boolean isLive=true;
	 //̹�˵ķ���
	 float direction=PI/4;
	 //��������
	 //�ӵ��ٶ���̹�˵�����
	 int bulletSpeed=speed*2;
	 //̹��λ�õļ���
	 System.out.println("̹�˵�ǰλ��:x="+x+"y="+y);
	 //̹�����Һ����˶�һ֡ʱ��λ�ñ仯
	 System.out.println("̹�����Һ����˶�һ֡");
	 x=x+speed;//x��.y����
	 System.out.println("̹�˵�ǰλ��:x1="+x+"y1="+y);
	 //̹�����������˶�һ֡ʱ��λ�ñ仯
	 System.out.println("̹�����������˶�һ֡");
	 y+=speed;//x���䣬y��
	 System.out.println("̹�˵�ǰλ��:x2="+x+"y2="+y);
	 //̹��б��45���˶�һ֡ʱ��λ�ñ仯
	 System.out.println("̹��б��45���˶�һ֡");
	 x+=speed Math.cos(direction);
	 //+=���Զ�ת��(floatתΪint)y+=speed Math.sin(direction);
	 System.out.println("̹�˵�ǰλ�ã�x3="+x+"y3="+y);
	 
	 
	 
	 
	}

}
