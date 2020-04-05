import java.util.Scanner;

public class Gauss{

    private static Scanner scanner = new Scanner(System.in);
    
    public static void main(String[] args){
        float[][] a = new float[3][4];
        float[] x = {0,0,0};
        int n = 3;
        int i,j,k,l;
        float temp,temp2;
        
        System.out.println("행렬 값을 입력하세요 ");
        for(i=1; i<=n; i++){
            for(j=1; j<=n+1; j++){
                a[i-1][j-1] = scanner.nextFloat();
            }
        }
        System.out.println();
        
        printmatrix(a,n);
    
        
        for(k=1; k<=n; k++){
                temp = a[k-1][k-1];
                if(temp == 0){    // a[i][i]의 값이 0일 경우 행을 교환해준다.
                    for(j=k; j<=n+1; j++){
                        for(l = k; l < n; l++){
                            if(a[l][j-1] != 0){
                                temp2 = a[k-1][j-1];
                                a[k-1][j-1] = a[l][j-1];
                                a[k][j-1] = temp2;
                                break;
                            }
                        }
                    }
                    temp = a[k-1][k-1];    // 행을 교환한 후 그 값을 temp에 저장해놓는다.
                }
                for(j=k; j<=n+1; j++){
                    a[k-1][j-1] = a[k-1][j-1]/temp;
                }
                for(i=k+1; i<=n; i++){
                    temp = a[i-1][k-1];
                    for(j=k; j<=n+1; j++){
                        a[i-1][j-1] = a[i-1][j-1] - temp*a[k-1][j-1];
                    }
                }
            System.out.println();
            printmatrix(a,n);
            
            }
            x[n-1] = a[n-1][n];
         
         
            for(k=n-1; k>=1; k--){
                x[k-1] = a[k-1][n];
                for(j= k+1; j<=n; j++){
                    x[k-1] = x[k-1] - a[k-1][j-1]*x[j-1];
                    a[k-1][j-1] = 0;
                }
                a[k-1][n] = x[k-1];
                System.out.println();
                
                printmatrix(a,n);
                
            }
            
        System.out.println("\n");
        System.out.println(String.format("x = %.6f ",x[0]));
        System.out.println(String.format("y = %.6f ",x[1]));
        System.out.println(String.format("z = %.6f ",x[2])); // x,y,z 값 출력하기
        System.out.println();
        }

    private static void printmatrix(float[][] a,int n){
        int i,j;
        for(i = 1; i<=n; i++){
            for(j=1; j<=n+1; j++){
                System.out.print(String.format("%.6f ",a[i-1][j-1]));
            }
            System.out.println();
        }
    } // 행렬 값을 보여주는 함수
}




