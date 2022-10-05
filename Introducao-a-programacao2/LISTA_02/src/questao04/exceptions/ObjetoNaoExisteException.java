package questao04.exceptions;

public class ObjetoNaoExisteException extends Exception {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	private Object objeto;

	public ObjetoNaoExisteException(Object obj) {
		super("Objeto requisitado n�o existe no reposit�rio.");
		this.objeto = obj;
	}

	public Object getObjeto() {
		return objeto;
	}

	public void setObjeto(Object objeto) {
		this.objeto = objeto;
	}

}
