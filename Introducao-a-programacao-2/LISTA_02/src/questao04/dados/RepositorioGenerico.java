package questao04.dados;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import questao04.exceptions.ObjetoJaAdicionadoException;
import questao04.exceptions.ObjetoNaoExisteException;

public class RepositorioGenerico<T> implements IRepositorioGenerico<T> {
	
	protected List<T> objetos;

	public RepositorioGenerico() {
		this.objetos = new ArrayList<>();
	}

	@Override
	public void adicionarObjetos(T novoObj) throws ObjetoJaAdicionadoException{
		if(!this.objetos.contains(novoObj)) {
			this.objetos.add(novoObj);
		} else{
			throw new ObjetoJaAdicionadoException(novoObj);
		}
	}

	@Override
	public void removerObjetos(T obj) throws ObjetoNaoExisteException{
		if(this.objetos.contains(obj)) {
			this.objetos.remove(this.objetos.indexOf(obj));
		} else {
			throw new ObjetoNaoExisteException(obj);
		}
	}

	@Override
	public void atualizarObjeto(T novoObj) throws ObjetoNaoExisteException{
		if(this.objetos.contains(novoObj)) {
			int indice = this.objetos.indexOf(novoObj);
			this.objetos.set(indice, novoObj);
		} else {
			throw new ObjetoNaoExisteException(novoObj);
		}
	}

	@Override
	public List<T> listar() {
		return Collections.unmodifiableList(this.objetos);
	}
}
