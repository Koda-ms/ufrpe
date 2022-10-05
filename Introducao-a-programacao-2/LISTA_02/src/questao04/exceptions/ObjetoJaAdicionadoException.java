package questao04.exceptions;

public class ObjetoJaAdicionadoException extends Exception {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	private Object objeto;
	
	public ObjetoJaAdicionadoException(Object obj) {
		super("Objeto j� adicionado ao reposit�rio, logo n�o poder� ser registrado novamente.");
		this.objeto = obj;
	}

	public Object getObjeto() {
		return objeto;
	}

	public void setObjeto(Object objeto) {
		this.objeto = objeto;
	}
}
