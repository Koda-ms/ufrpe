
import java.util.Collection;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author sidneynogueira
 */
public class Main {
    
    public static void main(String[] args) {
        MeuMapeamento<Integer, String> mis = new MeuMapeamento<>();
        mis.insere(1, "a");
        mis.insere(2, "b");
        mis.insere(3, "c");
        
        boolean v1 = (null == mis.valor(4));
        System.out.println(v1);//true
        
        String v2 = mis.valor(1);
        System.out.println(v2);//"a"
        
        mis.insere(1, "a2");

        Collection<Integer> chaves = mis.chaves();
        String sc = "";
        for (Integer chave : chaves) {
            sc += chave + ",";
        }
        System.out.println(sc);//1,2,3,

        Collection<String> valores = mis.valores();
        String sc2 = "";
        for (String valor : valores) {
            sc2 += valor + ",";
        }
        System.out.println(sc2);//a2,b,c,
        
        MeuMapeamento<String, String> mss = new MeuMapeamento<>();
        mss.insere("1", "a");
        mss.insere("2", "b");
        mss.insere("3", "c");
        
    } 
    
}
