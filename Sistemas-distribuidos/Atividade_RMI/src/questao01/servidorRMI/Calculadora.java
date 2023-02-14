package questao01.servidorRMI;

import java.rmi.server.UnicastRemoteObject;
import java.rmi.RemoteException;
import questao01.calcRMIinterface.ICalculadora;

public class Calculadora extends UnicastRemoteObject implements ICalculadora{  

   protected Calculadora() throws RemoteException {
		super();
	}
   
   @Override
   public double soma(double x, double y) throws RemoteException {
      return x + y;
   }

   @Override
   public double subtracao(double x, double y) throws RemoteException{
      return x - y;
   }
   
   @Override
   public double multiplicacao(double x, double y) throws RemoteException{
      return x * y;
   }

   @Override
   public double divisao(double x, double y) throws RemoteException{
      return x / y;
   }

   @Override
   public double logaritmoE(int logaritmando) throws RemoteException{
      return Math.log(logaritmando);
   }

   @Override
   public double logaritmo10(int logaritmando) throws RemoteException{
      return Math.log10(logaritmando);
      
   }

   @Override
   public double exponenciacao(double base, double expo) throws RemoteException{
      return Math.pow(base, expo);
   }

   @Override
   public double seno(double cOposto, double hipotenusa) throws RemoteException{
      return cOposto / hipotenusa;
   }

   @Override
   public double cosseno(double cAdjascente, double hipotenusa) throws RemoteException{
      return cAdjascente / hipotenusa;
   }

   @Override
   public double raizQuadrada(int x) throws RemoteException{
      return Math.sqrt(x);
   }
}