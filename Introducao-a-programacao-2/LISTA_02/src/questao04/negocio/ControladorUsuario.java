package questao04.negocio;

import java.util.List;

import questao04.dados.IRepositorioGenerico;
import questao04.dados.RepositorioGenerico;
import questao04.exceptions.ObjetoJaAdicionadoException;
import questao04.exceptions.ObjetoNaoExisteException;
import questao04.negocio.beans.Usuario;

public class ControladorUsuario {

	private IRepositorioGenerico<Usuario> repoUsuario;

	public ControladorUsuario() {
		this.repoUsuario = new RepositorioGenerico<>();
	}
	
	public void adicionar(Usuario u) throws ObjetoJaAdicionadoException {
		this.repoUsuario.adicionarObjetos(u);
	}
	
	public void remover(Usuario u) throws ObjetoNaoExisteException {
		this.repoUsuario.removerObjetos(u);
	}
	
	public void atualziar(Usuario u) throws ObjetoNaoExisteException {
		this.repoUsuario.atualizarObjeto(u);
	}
	
	public List<Usuario> listar(){
		return this.repoUsuario.listar();
	}
}
