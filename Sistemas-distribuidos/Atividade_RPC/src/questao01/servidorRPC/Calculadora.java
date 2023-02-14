package questao01.servidorRPC;

public class Calculadora {  
   
    public double soma(double x, double y) {
      return x + y;
    }

    public double subtracao(double x, double y){
      return x - y;
    }
   
    public double multiplicacao(double x, double y){
      return x * y;
    }

    public double divisao(double x, double y){
      return x / y;
    }

    public double logaritmoE(int logaritmando){
      return Math.log(logaritmando);
    }

    public double logaritmo10(int logaritmando){
      return Math.log10(logaritmando);  
    }   

   public double exponenciacao(double base, double expo){
      return Math.pow(base, expo);
   }

    public double seno(double cOposto, double hipotenusa){
      return cOposto / hipotenusa;
    }

    public double cosseno(double cAdjascente, double hipotenusa){
      return cAdjascente / hipotenusa;
    }

    public double raizQuadrada(int x){
      return Math.sqrt(x);
    }
}