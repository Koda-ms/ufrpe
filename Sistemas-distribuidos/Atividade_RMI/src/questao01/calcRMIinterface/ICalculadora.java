package questao01.calcRMIinterface;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface ICalculadora extends Remote{
    
    double soma(double x, double y) throws RemoteException;
    double subtracao(double x, double y) throws RemoteException;
    double multiplicacao(double x, double y) throws RemoteException;
    double divisao(double x, double y) throws RemoteException;
    double logaritmoE(int logaritmando) throws RemoteException;
    double logaritmo10(int logaritmando) throws RemoteException;
    double exponenciacao(double base, double expo) throws RemoteException;
    double seno(double cOposto, double hipotenusa) throws RemoteException;
    double cosseno(double cAdjascente, double hipotenusa) throws RemoteException;
    double raizQuadrada(int x) throws RemoteException;

}