package questao04.negocio;

import java.util.List;

import questao04.dados.IRepositorioGenerico;
import questao04.dados.RepositorioGenerico;
import questao04.exceptions.ObjetoJaAdicionadoException;
import questao04.exceptions.ObjetoNaoExisteException;
import questao04.negocio.beans.Loja;
import questao04.negocio.beans.Produto;
import questao04.negocio.beans.Usuario;

public class ControladorLoja {

	private IRepositorioGenerico<Loja> repoLoja;
	
	public ControladorLoja() {
		this.repoLoja = new RepositorioGenerico<>(); 
	}
	
	public void adicionar(Loja l) throws ObjetoJaAdicionadoException {
		this.repoLoja.adicionarObjetos(l);
	}
	
	public void remover(Loja l) throws ObjetoNaoExisteException {
		this.repoLoja.removerObjetos(l);
	}
	
	public void atualziar(Loja l) throws ObjetoNaoExisteException {
		this.repoLoja.atualizarObjeto(l);
	}
	
	public List<Loja> listar(){
		return this.repoLoja.listar();
	}
}
