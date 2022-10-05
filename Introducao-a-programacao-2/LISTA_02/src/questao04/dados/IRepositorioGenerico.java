package questao04.dados;

import java.util.List;

import questao04.exceptions.ObjetoJaAdicionadoException;
import questao04.exceptions.ObjetoNaoExisteException;

public interface IRepositorioGenerico<T> {
	List<T> listar();
	
	void adicionarObjetos(T novoObj) throws ObjetoJaAdicionadoException;
	
	void removerObjetos(T obj) throws ObjetoNaoExisteException;
	
	void atualizarObjeto(T novoObj) throws ObjetoNaoExisteException;
}
