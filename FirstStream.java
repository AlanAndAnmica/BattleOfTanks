package stream;

import java.util.stream.IntStream;
public class FirstStream {
	public static void main(String[] args) {
		System.out.printf("Sum of 1 through 10 is: %d%n", 
				IntStream.range(10, 110)
//				.map(( x) -> {return x * 2;})
//				.map((x) -> x * 3)
//				.map(y -> y + 2)
				.limit(5)//体现了lazy运算
//				.filter(x -> {
//					System.out.printf("filter x: %d%n", x);
//					return x < 4;})
				.map( (x ) -> {System.out.printf("element value: %d%n", x);
				return x * 1;})
				
				//.reduce((int x, int y) -> Math.min(x, y)));
				.sum());
		//
	}
}
