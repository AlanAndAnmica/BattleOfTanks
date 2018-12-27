package game;

public class screen {
	public static void main(String[]arges){
		//游戏参数的表示//游戏窗口的的大小（单位像素）
	 final int WINDOW_WIDTH=800;
	 final int WINDOW_HEIGHT=800;
	 final float PI=3.1415926F;
	 //坦克的位置
	 int x=0;
	 int y=0;
	 //坦克的大小
	 int w=50;int h=50;
	 //坦克的速度
	 int speed=10;
	 //坦克的生命
	 boolean isLive=true;
	 //坦克的方向
	 float direction=PI/4;
	 //参数计算
	 //子弹速度是坦克的两倍
	 int bulletSpeed=speed*2;
	 //坦克位置的计算
	 System.out.println("坦克当前位置:x="+x+"y="+y);
	 //坦克向右横向运动一帧时的位置变化
	 System.out.println("坦克向右横向运动一帧");
	 x=x+speed;//x变.y不变
	 System.out.println("坦克当前位置:x1="+x+"y1="+y);
	 //坦克向下纵向运动一帧时的位置变化
	 System.out.println("坦克向下纵向运动一帧");
	 y+=speed;//x不变，y变
	 System.out.println("坦克当前位置:x2="+x+"y2="+y);
	 //坦克斜向45度运动一帧时的位置变化
	 System.out.println("坦克斜向45度运动一帧");
	 x+=speed Math.cos(direction);
	 //+=会自动转型(float转为int)y+=speed Math.sin(direction);
	 System.out.println("坦克当前位置：x3="+x+"y3="+y);
	 
	 
	 
	 
	}

}
