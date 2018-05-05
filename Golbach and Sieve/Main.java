//***************************************
//		Steffen Chirichiello            *
//			CS113-005					*
//			31389364					*
//***************************************
public class Main {
	
	public static void main(String[] args){
		
		int firstArg;
		int[] array = new int[1000000];
		
		if (args.length > 0) {
			
		    try {
		  
		        firstArg = Integer.parseInt(args[0]);
		        if(firstArg > 0)
		        {
		        	int[] arr = new int[firstArg];
		        	sieve(arr);
		        	goldbach(arr);
		        	
		        }
		        else
		        {
		        	System.err.println("Must be a positve integer greater than zero");
		        	System.exit(1);
		        }

		        
		    }//end try
		    
		    catch (NumberFormatException e) {
		    	
		        System.out.println("Argument" + args[0] + " must be a positive integer greater than zero.");
		        System.exit(1);
		    }//end catch
		}//end if
		
		else{
			
			sieve(array);
			goldbach(array);
		}//end else
		
	}//end main

	
	public static void sieve(int[] array){
		
		int n = 2;
		//populate array
		for(int i = 0; i < array.length; i ++){
			
			array[i] = i + 1;
			//System.out.println(array[i]);
		}
		//set 1 to not prime
		array[0] = 0;
		//determine prime numbers
		while(n <= Math.sqrt(array.length)){
			
			for(int i = (n - 1); i + n < array.length; i += n){
				
				if(array[i + n] > array.length){
					break;
				}
				
				array[i + n] = 0;
			}
			
			n += 1;
		}
}//end sieve
	
	public static void goldbach(int[] array){
		
		int even = 4;
		
		for(int i = 0; i < array.length; i ++){
	
		System.out.print(array[i] +" " );
	}
		
		if(array.length < 4){
			
			System.err.println("argument must be 4 or higher to display two prime numbers adding up to all the even numbers");
		}
		System.out.println();
			
			for(int j = 1; j < array.length;j++){
			
				for(int i = 1; i < array.length; i++){
				
					if(array[i] + array[j] == even){
						if(even <= array.length){
							System.out.println(array[i] + " + " + array[j] + " = " + " " + even);
							even += 2;
							//break;
						}//end if
					}//end if
					
					if(j == 89){//j gets stuck at 89
						j = 2;// start j over
						break;
					}
				}
			}
}//end goldbach
}//end Main