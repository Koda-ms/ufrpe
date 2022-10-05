
import java.util.ArrayList;
import java.util.Collection;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author sidneynogueira
 */

public class MeuMapeamento<C,V> implements IMeuMapeamento<C,V> {

  ArrayList<C> chaves;
  ArrayList<V> valores;

  public MeuMapeamento(){
    this.chaves = new ArrayList<C>();
    this.valores = new ArrayList<V>();
  }
  
  @Override
  public void insere(C chave, V valor) {

    if(!this.chaves.contains(chave)){
      this.chaves.add(chave);
      this.valores.add(valor);
    } else{
      this.valores.set(this.chaves.indexOf(chave), valor);
    } // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
  }

  @Override
  public V valor(C chave) {
    if(this.chaves.contains(chave)){
      return this.valores.get(this.chaves.indexOf(chave));
    } else{
      return null;
    }
    // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
  }

  @Override
  public Collection<V> valores() {
    return this.valores; 
    // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
  }

  @Override
  public Collection<C> chaves() {
    return this.chaves;
    // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
  }
}
