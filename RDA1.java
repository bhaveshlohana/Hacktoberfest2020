import java.util.*;


public class RDA1 {
	
		static int i= -1; 
	
		public static int advance(String s)
		{
			i++;
			return s.charAt(i);
		}
		
		public static boolean S(String s) 
		{
			char a = (char) advance(s);
			if(a == 'a' | a == '^')
			{
				return true;
			}
			else if(a == '(')
			{
				boolean res = T(s);
				if(res == true)
				{
					a = (char) advance(s);
					if(a == ')')
						return true;
					return false;
				}
			}
			
			return false;
		}
		
		public static boolean T(String s)
		{
			
			if(S(s) == true)
			{
				if(T1(s) == true)
				{
					return true;
				}
				return false;
			}
			return false;
		}
		
		public static boolean T1(String s)
		{
			char a = (char) advance(s);
			if(a == ',')
			{
				if(S(s) == true)
				{
					if(T1(s) == true)
						return true;
					return false;
				}
				return false;
			}
			return true;
		}
		
		public static void main(String[] args)
		{
			Scanner sc = new Scanner(System.in); 
			System.out.println("Enter the string concatenated with $ in the end");
			String s = sc.next();
			
			/* For the Grammar:
			 *
			 * S -> a | ^ | (T)
			 * T -> ST'
			 * T' -> ,ST’ | E
			 * 
			 */
			
			boolean result = S(s);

			if(result == true && advance(s) == '$') {
				System.out.println("\nPassed Successfully");
			}
			else
				System.out.println("Parse error!!!");
			
		}
		
		
}
