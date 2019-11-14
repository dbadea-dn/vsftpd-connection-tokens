#include <sys/types.h>
#include <sys/ipc.h>

#include "builddefs.h"
#include "sysutil.h"
#include "session.h"
#include "sharedstate.h"

#ifdef VSF_BUILD_SHARED_STATE

void
shared_state_setup(struct vsf_session* p_sess, const char *path)
{
  p_sess->shared.sem_id = vsf_sysutil_sem_init(path);
  p_sess->shared.shm_id = vsf_sysutil_shm_init(path,
                                               sizeof(struct vsf_shared_state),
                                               (void**)&p_sess->shared.state);
}

void
shared_state_lock(struct vsf_session* p_sess)
{
  vsf_sysutil_sem_take(p_sess->shared.sem_id);
}

void
shared_state_unlock(struct vsf_session* p_sess)
{
  vsf_sysutil_sem_release(p_sess->shared.sem_id);
}

#endif /* VSF_BUILD_SHAREDSTATE */
