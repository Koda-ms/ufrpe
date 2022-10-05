
import java.util.Collection;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Interface.java to edit this template
 */

/**
 *
 * @author sidneynogueira
 * @param <C> Tipo para a chave
 * @param <V> Tipo para o valor
 */
public interface IMeuMapeamento<C, V> {

    /**
     * Insere o par valor/chave no mapeamento. Se chave existe, o valor
     * associado é atualizado com o valor fornecido.
     *
     * @param chave A chave
     * @param valor O valor
     */
    void insere(C chave, V valor);

    /**
     * Retorna o valor associado a chave.
     *
     * @param chave Chave cujo valor será retornado.
     * @return Valor associado a chave, null se chave não existir.
     */
    V valor(C chave);


    /**
     * Retorna os valores do mapeamento.
     *
     * @return Os valores do mapeamento.
     */
    Collection<V> valores();

    /**
     * Retorna as chaves do mapeamento.
     *
     * @return As chaves do mapeamento.
     */
    Collection<C> chaves();

}
